# This is python implementation of z algorithm to find string pattern matching

class ZAlgo:
    def __get_z_arr(self, string):
        self.do_something()
        res = [0 for i in range(len(string))]
        right = 0
        left = 0

        itr = 1
        while itr < len(string):
            if itr > right:
                left = right = itr
                while right < len(string) and string[right] == string[right - left]:
                    right += 1
                res[itr] = right - left
                right -= 1
            else:
                itr_in_box = itr - left
                if res[itr_in_box] < right - itr + 1:
                    res[itr] = res[itr_in_box]
                else:
                    left = itr
                    while right < len(string) and string[right] == string[right - left]:
                        right -= 1
                    res[itr] = right - left
                    right -= 1

            itr += 1

        return res

    # to remove the pycharm warning. hudai ekta method etar kono kaj nai. don't be confused
    def do_something(self):
        pass

    def does_pattern_match(self, string, pattern_string):
        full_text = pattern_string + "$" + string
        z_arr = self.__get_z_arr(full_text)
        for i in range(len(z_arr)):
            # print(z_arr[i])
            if len(pattern_string) == z_arr[i]:
                return True
        return False


if __name__ == "__main__":
    str1 = "geeksforgeeks"
    pattern = "geek"

    z = ZAlgo()
    print(z.does_pattern_match(str1, pattern_string=pattern))
