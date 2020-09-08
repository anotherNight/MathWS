//
//  RemoveDuplicates.swift
//  JDSwiftLeetCode
//
//  Created by 吴俊东 on 8/9/2020.
//  Copyright © 2020 吴俊东. All rights reserved.
//

import Foundation

/**
 题目大意 #

 给定一个有序数组 nums，对数组中的元素进行去重，使得原数组中的每个元素只有一个。最后返回去重以后数组的长度值。

 解题思路 #

 这里数组的删除并不是真的删除，只是将删除的元素移动到数组后面的空间内，然后返回数组实际剩余的元素个数，OJ 最终判断题目的时候会读取数组剩余个数的元素进行输出
 */
struct RemoveDuplicates: JDLeetCodeProtocol{
    func main() {
        var nums: [Int] = [0,0,1,1,1,2,2,3,3,4]
        print(removeDuplicates(&nums))
    }
    
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        if nums.count <= 1 {
            return nums.count
        }
        var len: Int = nums.count
        var index = 0
        while index < nums.count-1{
            if nums[index] == nums[index+1]{
                len -= 1
                nums.remove(at: index+1)
            }else{
                index += 1
            }
        }
        return len
    }
}
