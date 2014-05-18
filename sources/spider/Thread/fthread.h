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
#ifndef	__FTHREAD_H__
#define __FTHREAD_H__

#include <iostream>
#ifndef WIN32
#include <pthread.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#endif

namespace spider
{
    namespace Thread
    {
        typedef void (*FThreadFunc)(void *);

        class FThread{
        protected:
        #ifdef WIN32
            unsigned long id;
            void *handle;
        #else
            pthread_t pthread;
        #endif
            bool bStop;
            bool bRunning;

            FThreadFunc _call_back;
            void *_call_back_args;
        public:
            FThread();
            virtual ~FThread();
            int start();                    //开启线程，线程在这儿被创建
            void stop();                    //关闭线程,不释放自已
            void registCallBack(FThreadFunc callback,void *arg);

            bool isRunning(){
                return bRunning;
            }
            bool isStoped(){
                return bStop;
            }

        #ifdef WIN32
            static	unsigned long __stdcall thread_func(void *data){
        #else
            static	void *thread_func(void *data){
        #endif
                FThread *thread = (FThread *)data;
                thread->bRunning = true;
                thread->run();
                thread->bStop = false;
                return 0;
            }

            virtual void run(){
                if(_call_back != NULL){
                    (*_call_back)(_call_back_args);
                }
            };
            //线程定时器相关
            static	void start_timer();
            static	unsigned long get_tick();
            static 	void sleep(long ms);
        };
    }
}

#endif
