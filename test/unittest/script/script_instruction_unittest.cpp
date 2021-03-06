/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstring>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include "log.h"
#include "pkg_algorithm.h"
#include "script_instruction.h"
#include "script_manager.h"
#include "script_utils.h"
#include "thread_pool.h"
#include "unittest_comm.h"

using namespace std;
using namespace hpackage;
using namespace uscript;
using namespace updater;
using namespace testing::ext;

namespace {
class ScriptInstructionUnitTest : public ::testing::Test {
public:
    ScriptInstructionUnitTest() {}
    ~ScriptInstructionUnitTest() {}
    int TestScriptInstruction() const
    {
        return 0;
    }

protected:
    void SetUp() {}
    void TearDown() {}
    void TestBody() {}
};

HWTEST_F(ScriptInstructionUnitTest, TestScriptInstruction, TestSize.Level1)
{
    ScriptInstructionUnitTest test;
    EXPECT_EQ(0, test.TestScriptInstruction());
}
}
