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

#define QUEUE_CAPACITY 2
#include "es_result_queue.h"

ESResultQueue::ESResultQueue()
    : m_queue_capacity(QUEUE_CAPACITY) {
}

ESResultQueue::~ESResultQueue() {
}

std::reference_wrapper< ESResult > ESResultQueue::pop_front() {
    std::reference_wrapper< ESResult > es_result = m_queue.front();
    m_queue.pop();
    return es_result;
}

void ESResultQueue::pop() {
    m_queue.pop();
}

SQLRETURN ESResultQueue::push(std::reference_wrapper< ESResult > es_result) {
    if (m_queue.size() < m_queue_capacity) {
        m_queue.push(es_result);
        return SQL_SUCCESS;
    }
    return SQL_ERROR;
}

bool ESResultQueue::empty() {
    return m_queue.empty();
}

bool ESResultQueue::IsFull() {
    return (m_queue.size() >= m_queue_capacity) ? true : false;
}

void ESResultQueue::clear() {
    while (!m_queue.empty()) {
        m_queue.pop();
    }
}
