#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stdexcept>

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
            throw out_of_range("Out of bounds");
        }

        return data[index];
    }

    int idx(const vector<int> &coords)
    {
        if (coords.size() != shape.size())
        {
            throw invalid_argument(
                "Number of coordinates does not match tensor dimensions"
            );
        }

        int index = 0;

        for (int i = 0; i < coords.size(); i++)
        {
            if (coords[i] < 0 || coords[i] >= shape[i])
            {
                throw out_of_range("Coordinate out of bounds");
            }

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

    cout << "Number of elements: "
         << my_tensor.numel() << '\n';

    cout << "First element: "
         << my_tensor[0] << '\n';

    my_tensor[0] = 21;

    cout << "First element after modification: "
         << my_tensor[0] << '\n';

    int index = my_tensor.idx({0, 2, 3});

    cout << "Linear index: "
         << index << '\n';

    return 0;
}