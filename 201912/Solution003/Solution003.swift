import Foundation

class Solution003: NSObject {
    
    
    /// 通过哈希记录不同的字符和统计长度
    /// - Parameter s: s
    func lengthOfLongestSubstring(_ s: String) -> Int {
        if s.count == 0 {
            return 0
        }
        let list = Array(s)
        var dic: [String:Any] = [:]
        var max: Int = 0
        var preIndex: Int = 0
        var currentIndex: Int = 0
        while currentIndex < list.count {
            let c = list[currentIndex]
            if (dic[String(c)] != nil) {
                if max < dic.count {
                    max = dic.count
                }
                preIndex = preIndex + 1
                currentIndex = preIndex
                dic.removeAll()
            }else {
                currentIndex = currentIndex + 1
                dic[String(c)] = String(c)
            }
        }
        if dic.count > max {
            max = dic.count
        }
        return max
    }
    
    
    /// 搜索相同的两个字符串之间的间距
    /// - Parameter s: string
    func lengthOfLongestSubstring01(_ s: String) -> Int {
        guard !s.isEmpty else {
            return 0
        }
        let arr = Array(s.utf8)
        var len = 0
        var i = 0
        var j = 0
        var l = 0

        while j < arr.count {
            l = i
            while l < j {
                if arr[l] == arr[j] {
                    i = l + 1
                    break
                }
                
                l += 1
            }

            if j - i + 1 > len {
                len = j - i + 1
            }

            j += 1
        }
        
        return len
    }
}

