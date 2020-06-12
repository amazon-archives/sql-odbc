/*
 * Copyright <2019> Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 *
 */
#ifndef ES_RESULT_QUEUE
#define ES_RESULT_QUEUE

#include <queue>
#include <functional> 
#include "es_types.h"

class ESResultQueue {
   public:
    ESResultQueue();
    ~ESResultQueue();
    std::reference_wrapper< ESResult > pop_front();
    void pop();
    SQLRETURN push(std::reference_wrapper< ESResult > es_result);
    bool empty();
    bool IsFull();
    void clear();

   private:
    size_t m_queue_capacity;
    std::queue<std::reference_wrapper<ESResult>> m_queue;
};

#endif