static inline auto _ = []
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ofstream out("user.out", std::ios::out | std::ios::binary);
    out.rdbuf()->pubsetbuf(nullptr, 256);
    std::string s;
    std::noskipws(std::cin);
    while (std::getline(std::cin, s))
    {
        int count = 0;
        bool inNum = false;
        for (char c : s)
        {
            if (std::isdigit(c) != 0)
            {
                if (!inNum)
                {
                    ++count;
                    inNum = true;
                }
            }
            else
            {
                inNum = false;
            }
        }
        out << count << '\n';
    }
    std::skipws(std::cin);
    out.flush();
    exit(0);
    return 0;
}();

// class Solution
// {
// public:
//     int solve(TreeNode *root)
//     {
//         if (!root)
//             return 0;

//         int left = solve(root->left);
//         int right = solve(root->right);

//         return 1 + left + right;
//     }
//     int countNodes(TreeNode *root)
//     {
//         std::ios::sync_with_stdio(false);
//         std::cin.tie(nullptr);
//         std::cout.tie(nullptr);

//         return solve(root);
//     }
// };