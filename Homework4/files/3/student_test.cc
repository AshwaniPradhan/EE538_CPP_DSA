#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------


TEST(BSTStatisticsTest, BSTTest1) {
    // Create a tree.
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(10);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(6);
    root->left->right->left = new BinaryTreeNode(4);
    root->left->right->right = new BinaryTreeNode(7);
    root->right->right = new BinaryTreeNode(14);
    root->right->right->left = new BinaryTreeNode(13);
    
    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    // Get statistics of Tree
    std::map<Statistics, int> statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 4);
    EXPECT_EQ(statistics[Statistics::kMax], 14);
    EXPECT_EQ(statistics[Statistics::kMin], 1);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 4);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 9);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 2);
}



TEST(IsBSTTest, BSTTest2) 
{

    // Creating a tree.
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(10);
    root->left->left = new BinaryTreeNode(1);
    root->left->right = new BinaryTreeNode(6);
    root->left->right->left = new BinaryTreeNode(4);
    root->left->right->right = new BinaryTreeNode(7);
    root->right->right = new BinaryTreeNode(14);
    root->right->right->left = new BinaryTreeNode(13);
    
    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));
}


TEST(IsBSTTest, BSTTest3) 
{
    // Only one node.
    BinaryTreeNode* root1 = new BinaryTreeNode(1);
    EXPECT_TRUE(IsBST(root1));
}

TEST(IsBSTTest, BSTest4) {
    // Create a bad tree.
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(6);
    root->right = new BinaryTreeNode(7);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(4);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(5);
    
    // Check if the tree is a BST.
    EXPECT_FALSE(IsBST(root));
}

TEST(BSTStatisticsTest, BSTest5) {
    // Create a tree.
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(7);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(4);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(8);
    
    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    // Get statistics of Tree
    std::map<Statistics, int> statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 3);
    EXPECT_EQ(statistics[Statistics::kMax], 8);
    EXPECT_EQ(statistics[Statistics::kMin], 2);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 4);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 7);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 0);
}


TEST(BSTStatisticsTest, BSTest6) {
    // Create a tree.
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(7);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(4);
    root->right->left = new BinaryTreeNode(6);

    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    // Get statistics of Tree
    std::map<Statistics, int> statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 3);
    EXPECT_EQ(statistics[Statistics::kMax], 7);
    EXPECT_EQ(statistics[Statistics::kMin], 2);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 3);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 6);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 1);
}

TEST(BSTStatisticsTest, BStest7) {
    // Create a tree.
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(7);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(4);

    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    // Get statistics of Tree
    std::map<Statistics, int> statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 3);
    EXPECT_EQ(statistics[Statistics::kMax], 7);
    EXPECT_EQ(statistics[Statistics::kMin], 2);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 3);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 5);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 0);
}

TEST(BSTStatisticsTest, BStest8) {
    // Create a tree.
    BinaryTreeNode* root = new BinaryTreeNode(5);
    root->left = new BinaryTreeNode(3);
    root->right = new BinaryTreeNode(7);
    
    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    // Get statistics of Tree
    std::map<Statistics, int> statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 2);
    EXPECT_EQ(statistics[Statistics::kMax], 7);
    EXPECT_EQ(statistics[Statistics::kMin], 3);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 2);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 3);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 0);

    // Delete the right node
    root->right = nullptr;

    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 2);
    EXPECT_EQ(statistics[Statistics::kMax], 5);
    EXPECT_EQ(statistics[Statistics::kMin], 3);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 1);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 2);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 1);

    // Delete the left node
    root->left = nullptr;
    
    // Check if the tree is a BST.
    EXPECT_TRUE(IsBST(root));

    statistics = FindStatistics(root);

    EXPECT_EQ(statistics[Statistics::kHeight], 1);
    EXPECT_EQ(statistics[Statistics::kMax], 5);
    EXPECT_EQ(statistics[Statistics::kMin], 5);
    EXPECT_EQ(statistics[Statistics::kNumberOfLeaves], 1);
    EXPECT_EQ(statistics[Statistics::kNumberOfNodes], 1);
    EXPECT_EQ(statistics[Statistics::kNumberOfSingleChildNodes], 0);
}


