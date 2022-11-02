/**
 * @file Hook.cpp
 * @author JIANG Yicheng  RM2023 (EthenJ@outlook.sg)
 * @brief
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "FreeRTOS.h"
#include "task.h"

#define GG()     \
    while (true) \
    __asm volatile("bkpt")

namespace Core
{
namespace Diagnostic
{

extern "C"
{
    void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
    {
        GG();  // One of your tasks has stack overflow hence we stop your code here
        /**
         *      To solve this problem, you may try to:
         *          1. Increase the stack size of the task
         *          2. Check if you have any recursive function
         **/
    }

    void vApplicationMallocFailedHook(void)
    {
        GG();  // Memory allocation failed hence we stop your code here
        /**
         *      We do not allow you to use dynamic memory allocation in the internal competition and further development
         **/
    }

    void vApplicationTaskReturnHook(void)
    {
        GG();  // One of your tasks has returned hence we stop your code here
        /**
         *      To solve this problem, you may try to:
         *          1. Check whether you have the infinite loop in your task
         *          2. Check whether you have statement that may cause the task to return (eg. return, break)
         **/
    }

    void __cxa_pure_virtual(void)
    {
        GG();  // You have called a pure virtual function
        /**
         *      What are you doing??? How you pass the compilation???? Check your code now!!!
         **/
    }

    void assertFailed(uint8_t *file, uint32_t line)
    {
        GG();  // Assertion failed hence we stop your code here
        /**
         *      To solve this problem, you may try to:
         *          1. Check whether you used the wrong FreeRTOS API (eg. ISR API in task)
         *          2. Check whether you passed the wrong parameter to the FreeRTOS API
         *          3. Check whether you used FreeRTOS API in a wrong way (eg. use xTaskCreateStatic() in ISR)
         *          4. Check whether you used FreeRTOS API in ISR whose priority is too high (check CubeMX)
         **/
    }

    __attribute__((weak)) void assert_failed(uint8_t *file, uint32_t line) { assertFailed(file, line); }

    void hardFault(void)
    {
        GG();  // Hard fault occurred hence we stop your code here
        /**
         *     To solve this problem, you may try to:
         *          1. Check whether you accessed the memory out of range (especially arrays)
         *          2. Check whether you have accessed a null pointer
         *          3. Check whether you have made illegal register operation
         *          4. Check whether you have create a critical section that is too long
         *
         *     Notice:
         *          1. Divide by zero should not cause hard fault on STM32 without specific configuration
         */
    }
}
}  // namespace Diagnostic
}  // namespace Core
