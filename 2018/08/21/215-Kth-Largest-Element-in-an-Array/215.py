def partition(nums, left, r):
    pivot = nums[left]
    l = left+1
    while l <= r:
        if nums[l] < pivot and nums[r] > pivot:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        if nums[l] >= pivot:
            l += 1
        if nums[r] <= pivot:
            r -= 1
    nums[left], nums[r] = nums[r], nums[left]
    return r


nums = [-4,-2,-3,-4]
k = 1
l, r = 0, len(nums)-1
while True:
    p = partition(nums, l, r)
    if p == k - 1:
        print(nums)
        print(nums[p])
        break
    elif p < k-1:
        l = p+1
    else:
        r = p-1