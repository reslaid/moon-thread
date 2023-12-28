// thread_tools.h

#ifndef THREAD_TOOLS_H
#define THREAD_TOOLS_H

#include <thread>
#include <mutex>
#include <sstream>
#include <thread>
#include <chrono>
#include <functional>
#include <cstring>


#ifdef _WIN32
#ifdef THREAD_TOOLS_EXPORTS
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif
#else
#define DLL_EXPORT
#endif


extern "C" {

    DLL_EXPORT typedef void (*ThreadFunction)(void*);

    DLL_EXPORT struct ThreadInfo {
        std::thread* thread;
        std::mutex mutex;
    };

    // Function to create a thread
    DLL_EXPORT ThreadInfo* create_thread(ThreadFunction start_routine, void* arg);

    // Function to join a thread
    DLL_EXPORT void join_thread(ThreadInfo* threadInfo);

    // Function to delete the thread info structure
    DLL_EXPORT void delete_thread_info(ThreadInfo* threadInfo);

    // Function to detach a thread
    DLL_EXPORT void detach_thread(ThreadInfo* threadInfo);

    // Function to get the native thread handle
    DLL_EXPORT void* get_native_handle(ThreadInfo* threadInfo);

    // Function to yield the processor to another thread
    DLL_EXPORT void yield_thread();

    // Function to sleep for a specified duration (in milliseconds)
    DLL_EXPORT void sleep_for(int milliseconds);

    // Function to get the thread ID
    DLL_EXPORT unsigned long get_thread_id(ThreadInfo* threadInfo);

    // Function to set the thread name (if supported)
    DLL_EXPORT void set_thread_name(const char* name);

    // Function to get the number of hardware threads
    DLL_EXPORT unsigned int get_hardware_threads();

    // Function to get the current thread name (if supported)
    DLL_EXPORT const char* get_current_thread_name();

    // Function to check if the current thread is the same as the provided thread
    DLL_EXPORT bool is_current_thread(ThreadInfo* threadInfo);

    // Function to get the number of milliseconds elapsed since program start
    DLL_EXPORT unsigned long long get_elapsed_time();

    // Function to get the current timestamp as a string
    DLL_EXPORT const char* get_current_timestamp();

    // Function to check if a thread is still running
    DLL_EXPORT bool is_thread_running(ThreadInfo* threadInfo);
}

#endif