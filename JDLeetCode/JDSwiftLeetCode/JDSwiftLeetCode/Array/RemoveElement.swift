//
//  RemoveElement.swift
//  JDSwiftLeetCode
//
//  Created by 吴俊东 on 8/9/2020.
//  Copyright © 2020 吴俊东. All rights reserved.
//

import Foundation

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
