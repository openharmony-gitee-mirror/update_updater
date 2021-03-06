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

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "utils.h"

using namespace updater;
using namespace testing::ext;
using namespace std;

namespace updater_ut {
class UtilsUnitTest : public testing::Test {
public:
    static void SetUpTestCase(void) {};
    static void TearDownTestCase(void) {};
    void SetUp() {};
    void TearDown() {};
};

HWTEST_F(UtilsUnitTest, updater_utils_test_001, TestSize.Level0)
{
    string emptyStr = utils::Trim("");
    EXPECT_STREQ(emptyStr.c_str(), "");
    emptyStr = utils::Trim("   ");
    EXPECT_STREQ(emptyStr.c_str(), "");
    emptyStr = utils::Trim("aa   ");
    EXPECT_STREQ(emptyStr.c_str(), "aa");
}

HWTEST_F(UtilsUnitTest, updater_utils_test_002, TestSize.Level0)
{
    uint8_t a[1] = {0};
    a[0] = 1;
    string newStr = utils::ConvertSha256Hex(a, 1);
    EXPECT_STREQ(newStr.c_str(), "01");
}

HWTEST_F(UtilsUnitTest, updater_utils_test_003, TestSize.Level0)
{
    string str = "aaa\nbbb";
    vector<string> newStr = utils::SplitString(str, "\n");
    EXPECT_EQ(newStr[0], "aaa");
    EXPECT_EQ(newStr[1], "bbb");
}

HWTEST_F(UtilsUnitTest, updater_utils_test_004, TestSize.Level0)
{
    EXPECT_EQ(utils::MkdirRecursive("/data/xx?xx", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH), 0);
}

HWTEST_F(UtilsUnitTest, updater_utils_test_005, TestSize.Level0)
{
    string input = "";
    int output = utils::String2Int<int>(input, 10);
    EXPECT_EQ(output, 0);
    input = "0x01";
    output = utils::String2Int<int>(input, 10);
    EXPECT_EQ(output, 1);
}

HWTEST_F(UtilsUnitTest, updater_utils_test_006, TestSize.Level0)
{
    std::vector<std::string> files;
    string path = "/data";
    utils::GetFilesFromDirectory(path, files, true);
}
} // updater_ut
