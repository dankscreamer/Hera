#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class Tensor
{
private:
    vector<int> shape;
    vector<float> data;

public:
    Tensor(vector<int> sh)
    {
        shape = sh;
        int prd = 1;
        for (int i = 0; i < shape.size(); i++)
        {
            prd *= shape[i];
        }
        for (int i = 1; i <= prd; i++)
        {
            data.push_back(0);
        }
    }
    float &operator[](int index)
    {
        int n = data.size();
        if (index < 0 || index >= n)
        {
            throw std::out_of_range("Out of bounds");
        }

        return data[index];
    }
    int idx(const vector<int> &coords)
    {
        int index = 0;

        for (int i = 0; i < coords.size(); i++)
        {
            int stride = 1;

            for (int j = i + 1; j < shape.size(); j++)
            {
                stride *= shape[j];
            }

            index += coords[i] * stride;
        }

        return index;
    }

    vector<int> const &dim()
    {

        return shape;
    }
    int numel()
    {
        return data.size();
    }
};
int main()
{
    vector<int> shape = {1, 3, 4};
    Tensor my_tensor(shape);
    int sz = my_tensor.numel();

    vector<int> const &ans = my_tensor.dim();
    cout << my_tensor[0] << '\n';
    my_tensor[0] = 21;
    cout << my_tensor[0] << '\n';
    int tempo=my_tensor.idx({0,0,0});
    cout << tempo;

    return 0;
}