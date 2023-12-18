#include <map>
#include <iostream>
#include <fstream>

#include <gtest/gtest.h> //  TODO why do i need gtest.h here??
#include <gmock/gmock.h>

#include "process_input.h"
#include "io.h"

class SplitTest : public testing::Test {
    protected:
        std::string input;
        std::vector<std::string> expected;

        void SetUp() override {
             delimiter = "dd";
        };
        void run_test() {
            std::vector<std::string> result = split(input, delimiter);
            EXPECT_EQ(expected, result);
        }
    private:
    std::string delimiter;
};

TEST_F(SplitTest, TestManySplits) {
    input = "ThisddHasddManyddParts!";
    expected = {"This", "Has", "Many", "Parts!"};
    run_test();
}

TEST_F(SplitTest, TestNoSplit) {
    input = "This should not be split up";
    expected = {"This should not be split up"};
    run_test();
}

TEST_F(SplitTest, TestSplitAtEnd) {
    input = "SplitAtTheEnd dd";
    expected = {"SplitAtTheEnd "};
    run_test();
}

TEST_F(SplitTest, TestSplitAtBegin) {
    input = "dd SplitAtTheStart";
    expected = {" SplitAtTheStart"};
    run_test();
}


// TestEmptyString: not sure about what correct behaviour should be
TEST_F(SplitTest, TestEmptyString) {
    input = "";
    expected = {};
    run_test();
}


class TestGetNumbersFromString : public testing::Test {
    protected:
        std::string input;
        std::vector<int> expected;
        void run_test() {
            std::vector<int> result = get_numbers_from_string(input, " ");
            EXPECT_EQ(expected, result);
        }
};

TEST_F(TestGetNumbersFromString, TestMultipleNumbers) {
    input ="56 0 12";
    expected = {56, 0, 12};
    run_test();
}

TEST_F(TestGetNumbersFromString, TestEmptyString) {
    input ="";
    expected = {};
    run_test();
}

TEST_F(TestGetNumbersFromString, TestOneNumber) {
    input ="9";
    expected = {9};
    run_test();
}


struct TestInput : Input {
    public:
    std::vector<std::string> read_lines;
    using Input::Input;

    private:
    void set_content(std::vector<std::string> lines) override {
        read_lines = lines;
    }
};


class PuzzleInputTest : public testing::Test {
    protected:
    static constexpr std::string test_files_dir()  { return TEST_FILES_DIR; };
    const std::string filename{test_files_dir() + "test.txt"};
    const std::vector<std::string> expected = {
        "Test1",
        "Test2",
        "Test3"
    };

    std::function<void()> test_method;
    TestInput *input_obj;

    void run_test() {
        test_method();
        EXPECT_EQ(input_obj->read_lines, expected);
    }
    void SetUp() {
        input_obj = new TestInput("Test Input");
    }

    void TearDown() {
        delete input_obj;
    }
};

TEST_F(PuzzleInputTest, TestStdinInput) {
    std::istringstream stream("3\nTest1\nTest2\nTest3\n");
    test_method = [this, &stream](){ this->input_obj->init_from_stream(stream); };
    run_test();
}

TEST_F(PuzzleInputTest, TestFileInput) {
    test_method = [this](){ this->input_obj->init_from_file(this->filename); };
    run_test();
}


int main(void) {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
