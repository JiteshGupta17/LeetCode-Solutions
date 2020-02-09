void sortColors(vector<int>& arr) {
    int ptr = 0;
    int itr = 0;
    int ptr_2 = arr.size() - 1;

    // Based on Keeping all 0s in begining and 2s at end
    // which automatically leads to 1s in middle
    while (itr <= ptr_2)
    {
        if (arr[itr] == 0)
        {
            swap(arr[itr], arr[ptr]);
            ptr++;
        }
        else if (arr[itr] == 2)
        {
            swap(arr[itr], arr[ptr_2]);
            ptr_2--;

            // we dont do itr++ in this becoz we dont know the element swapped here now
            continue;
        }

        itr++;
    }
}
