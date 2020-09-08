//
//  RemoveElement.swift
//  JDSwiftLeetCode
//
//  Created by 吴俊东 on 8/9/2020.
//  Copyright © 2020 吴俊东. All rights reserved.
//

import Foundation

/**
 题目 #

 Given an array nums and a value val, remove all instances of that value in-place and return the new length.

 Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

 The order of elements can be changed. It doesn’t matter what you leave beyond the new length.
 
 题目大意 #

 给定一个数组 nums 和一个数值 val，将数组中所有等于 val 的元素删除，并返回剩余的元素个数。
 */
struct RemoveElement: JDLeetCodeProtocol{
    func main() {
        var nums: [Int] = [0,0,1,1,1,2,2,3,3,4]
        print(RemoveElement(&nums, target: 2))
    }
    
    func RemoveElement(_ nums: inout [Int], target: Int) -> Int {
        var len: Int = nums.count
        var index = nums.count - 1
        while index >= 0{
            if nums[index] == target{
                len -= 1
                nums.remove(at: index)
            }
            index = index - 1
        }
        return len
    }
}
