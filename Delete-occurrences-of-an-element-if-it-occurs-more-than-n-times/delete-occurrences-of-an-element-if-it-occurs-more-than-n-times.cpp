std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> return_arr;
    for (auto &&i : arr)
    {
        int nr_occ = std::count(return_arr.begin(), return_arr.end(), i);
        if (nr_occ < n)
        {
            return_arr.push_back(i);
        }
    }
    return return_arr;
}