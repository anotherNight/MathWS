//
//  ThirdNumSum.swift
//  JDSwiftLeetCode
//
//  Created by 吴俊东 on 8/9/2020.
//  Copyright © 2020 吴俊东. All rights reserved.
//


/**
 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

 注意：答案中不可以包含重复的三元组。

  

 示例：

 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

 满足要求的三元组集合为：
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]
 */

struct ThirdNumSum:JDLeetCodeProtocol {
    func main() {
        let nums: [Int] = [-4,-5,-24,-11,-3,-4,0,-4,-3,-2,2,3,5,7,8,5,2,11,23,4,2,4]
        print(threeSum(nums).description)
    }
    
    func threeSum(_ nums: [Int]) -> [[Int]] {
        if nums.count < 3 {
            return []
        }
        let nums = nums.sorted()
        var res = [[Int]]()
        for i in 0..<nums.count - 2 {
            //最小的数大于0直接跳出循环
            if nums[i] > 0 {
                break
            }
            //跳过起点相同的
            if i > 0 && nums[i] == nums[i - 1] {
                continue
            }
            var l = i + 1
            var r = nums.count - 1
            
            while l < r {
                let result = nums[i] + nums[l] + nums[r]
                if result == 0 {
                    res.append([nums[i], nums[l], nums[r]])
                    //跳过第二第三个数相同的结果
                    repeat {
                        l += 1
                    } while l < r && nums[l] == nums[l - 1]
                    repeat {
                        r -= 1
                    } while l < r && nums[r] == nums[r + 1]
                } else if result < 0 {
                    //跳过第二第三个数相同的结果
                    repeat {
                        l += 1
                    } while l < r && nums[l] == nums[l - 1]
                } else {
                    //跳过第二第三个数相同的结果
                    repeat {
                        r -= 1
                    } while l < r && nums[r] == nums[r + 1]
                }
            }
        }
        return res
    }
}
