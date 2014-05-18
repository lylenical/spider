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
#include "fmutex.h"

using namespace spider::Thread;

FMutex::FMutex(){
#ifdef WIN32
	_mutex = new CRITICAL_SECTION;
	InitializeCriticalSection(_mutex);
#else
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(&_mutex,&attr);
#endif
}

FMutex::~FMutex(){
#ifdef WIN32
	DeleteCriticalSection(_mutex);
	delete _mutex;
#else
	pthread_mutex_destroy(&_mutex);
#endif
}

void FMutex::lock(){
#ifdef WIN32
	EnterCriticalSection(_mutex);
#else
	pthread_mutex_lock(&_mutex);
#endif
}

void FMutex::unlock(){
#ifdef WIN32
	LeaveCriticalSection(_mutex);
#else
	pthread_mutex_unlock(&_mutex);
#endif
}
