#include<iostream>
#include<string>
#include<array>

class ZAlgo{
public:
	bool does_matched(std::string str, std::string pattern){
		bool res = false;
		std::string final_string = pattern+"$"+str;

		std::array<int, 30> z;
		z = get_z_arr(final_string);
		for (int i=0;i < final_string.length(); i++) {
			if (z[i] == pattern.length()) {
				return true;
			}
		}
		return false;
	}

private:
	std::array<int, 30> get_z_arr(std::string str) {
		std::array<int, 30> z_arr;
		int right=0, left=0, itr = 1;
		std::cout<<str<<std::endl;
		for (itr = 1; itr < str.length(); itr++) {
			if (itr > right) {
				left = itr;
				right = itr;
				while( right < str.length() && str[right] == str[right-left]) {
					right++;
				}
				z_arr[itr] = right - left;
				right--;

			} else {
				int itr2 = itr - left;
				if (z_arr[itr2] < right - itr + 1){
					z_arr[itr] = z_arr[itr2];
				} else {
					left = itr2;
					while( right < str.length() && str[right] == str[right-left]) {
						right++;
					}
					z_arr[itr] = right - left;
					right--;
				}
			}
		}
		return z_arr;
	}
};


int main(int argc, char **argv) {
	std::string str = "geeksforgeeks";
	std::string pattern = "geek";

	ZAlgo z = ZAlgo();
	std::cout<<z.does_matched(str, pattern);
}