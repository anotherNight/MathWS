//
//  FourNumSum.swift
//  JDSwiftLeetCode
//
//  Created by 吴俊东 on 8/9/2020.
//  Copyright © 2020 吴俊东. All rights reserved.
//

import Foundation

struct FourNumSum: JDLeetCodeProtocol {
    func main() {
        let sums: [Int] = [1, 0, -1, 0, -2, 2]
        let target: Int = 0
        print(FourNumSum(sums, target: target).description)
    }
    
    func FourNumSum(_ nums: [Int], target: Int) -> [[Int]] {
        guard nums.count >= 4 else {
            return []
        }
        let sorted = nums.sorted()
        let count = sorted.count
        var arr = [[Int]]()
        for i in 0..<count - 3 {
            if i > 0 && sorted[i] == sorted[i - 1] {
                continue
            }
            guard sorted[i] + sorted[i + 1] + sorted[i + 2] + sorted[i + 3] <= target else {
                break
            }
            for j in i + 1..<count - 2 {
                // 跳过相同位
                if j > i + 1 && sorted[j] == sorted[j - 1] {
                    continue
                }
                //跳过i，j过小的情况
                guard sorted[i] + sorted[j] + sorted[count - 1] + sorted[count - 2] >= target else {
                    continue
                }
                //跳过i，j，j+1，j+2过大的情况
                guard sorted[i] + sorted[j] + sorted[j + 1] + sorted[j + 2] <= target else {
                    break
                }
                var l = j + 1
                var r = count - 1
                // 比较j+1~count-1之间的数
                while l < r {
                    let sum = sorted[i] + sorted[j] + sorted[l] + sorted[r]
                    if sum == target {
                        arr.append([sorted[i], sorted[j], sorted[l], sorted[r]])
                        while l < r && sorted[l] == sorted[l + 1] {
                            l += 1
                        }
                        while l < r && sorted[r] == sorted[r - 1] {
                            r -= 1
                        }
                        l += 1
                        r -= 1
                    } else if sum > target {
                        r -= 1
                    } else if sum < target {
                        l += 1
                    }
                }
            }
        }
        return arr
    }
}
