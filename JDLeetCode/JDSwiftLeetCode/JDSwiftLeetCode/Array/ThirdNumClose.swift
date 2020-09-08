//
//  ThirdNumClose.swift
//  JDSwiftLeetCode
//
//  Created by 吴俊东 on 8/9/2020.
//  Copyright © 2020 吴俊东. All rights reserved.
//

import Foundation

/**
 题目 #

 Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 Example:


 Given array nums = [-1, 2, 1, -4], and target = 1.

 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 题目大意 #

 给定一个数组，要求在这个数组中找出 3 个数之和离 target 最近。

 解题思路 #

 这一题看似和第 15 题和第 18 题很像，都是求 3 或者 4 个数之和的问题，但是这一题的做法和 15，18 题完全不同。

 这一题的解法是用两个指针夹逼的方法。先对数组进行排序，i 从头开始往后面扫。这里同样需要注意数组中存在多个重复数字的问题。具体处理方法很多，可以用 map 计数去重。这里笔者简单的处理，i 在循环的时候和前一个数进行比较，如果相等，i 继续往后移，直到移到下一个和前一个数字不同的位置。j，k 两个指针开始一前一后夹逼。j 为 i 的下一个数字，k 为数组最后一个数字，由于经过排序，所以 k 的数字最大。j 往后移动，k 往前移动，逐渐夹逼出最接近 target 的值。

 这道题还可以用暴力解法，三层循环找到距离 target 最近的组合。具体见代码。
 */
struct ThirdNumClose: JDLeetCodeProtocol {
    func main() {
//        let sums: [Int] = [-1, 2, 1, -4]
        let sums: [Int] = [1,1,-1,-1,3]
        let array = threeSum(sums, 1)
        print(array)
    }
    
    func threeSum(_ nums: [Int], _ target: Int) -> Int {
        if nums.count <= 3 {
            return nums.reduce(0, +)
        }
        
        let nums = nums.sorted()
        var res:[Int] = Array(nums[0...2])
        var sum: Int = res.reduce(0, +)
        
        for i in 0..<nums.count - 2 {
            //跳过起点相同的
            if i > 0 && nums[i] == nums[i - 1] {
                continue
            }
            
            var l = i + 1
            var r = nums.count - 1
            
            while l < r {
                let result = nums[i] + nums[l] + nums[r]
                if result - target == 0 {
                    return result
                } else if result - target < 0 {
                    if abs(sum - target) > abs(result - target) {
                        sum = result
                        res = [nums[i],nums[l],nums[r]]
                    }
                    
                    //跳过第二第三个数相同的结果
                    repeat {
                        l += 1
                    } while l < r && nums[l] == nums[l - 1]
                } else {
                    if abs(sum - target) > abs(result - target) {
                        sum = result
                        res = [nums[i],nums[l],nums[r]]
                    }
                    //跳过第二第三个数相同的结果
                    repeat {
                        r -= 1
                    } while l < r && nums[r] == nums[r + 1]
                }
            }
        }
        return sum
    }

}
