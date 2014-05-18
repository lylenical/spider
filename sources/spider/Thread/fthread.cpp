/****************************************************************************
 Copyright (c) 2014 www.fio-tech.com

 http://www.fio-tech.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "fthread.h"
#ifdef WIN32
#include <windows.h>
#endif

using namespace spider::Thread;

FThread::FThread(){
	bStop = false;
	bRunning = false;
	_call_back_args = NULL;
	_call_back = NULL;
#ifdef WIN32
	handle = 0;
#else
	memset(&pthread,0,sizeof(pthread));
#endif
}

FThread::~FThread(){
	if(!bStop){
		stop();
	}
}

int FThread::start(){
	if(bRunning){
		return -1;
	}
	bRunning = true;
	bStop = false;
#ifdef WIN32
	handle = CreateThread(0,0,thread_func,(LPVOID)this,0,&id);
	if(handle == 0){
		return -1;
	}
	else{
		return 0;
	}
#else
	pthread_attr_t __attr;
	pthread_attr_init(&__attr);
	pthread_attr_setdetachstate(&__attr,PTHREAD_CREATE_DETACHED);
	return pthread_create(&pthread,&__attr,thread_func,(void *)this);
#endif
}

void FThread::stop(){
	bStop = true;
	for(int i=0;bRunning && i<30;i++){
		FThread::sleep(100);
	}
#ifdef WIN32
	if(bRunning){
		TerminateThread(handle,0);
	}
	if(handle){
		CloseHandle(handle);
	}
#else
	if(bRunning){
		pthread_cancel(pthread);
	}
	memset(&pthread,0,sizeof(pthread));
#endif
	bRunning = false;
}

void FThread::sleep(long ms){
#ifdef WIN32
	Sleep(ms);
#else
	usleep(ms * 1000);
#endif
}

unsigned long _start_count = 0;
#ifndef WIN32
long _start_usecond;
#endif


void FThread::start_timer(){
#ifdef WIN32
	_start_count = GetTickCount();
#else
	struct timeval tv;
	gettimeofday(&tv,0);
	_start_count = tv.tv_sec;
	_start_usecond = tv.tv_usec;
#endif
}

unsigned long FThread::get_tick(){
#ifdef WIN32
	return GetTickCount() - _start_count;
#else
	struct timeval tv;
	gettimeofday(&tv,0);
	return (tv.tv_sec - _start_count)*1000 + (tv.tv_usec - _start_usecond)/1000;
#endif
}

void FThread::registCallBack(FThreadFunc callback,void *arg){
    _call_back = callback;
    _call_back_args = arg;
}


