class Solution:
    def containsDuplicate(self, nums: list) -> bool:
        record = set()
        for num in nums:
            if num in record:
                return True
            else:
                record.add(num)
        return False
