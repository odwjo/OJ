
void tree_add(int *tree, int size, int val)
{
    val += 1;
    while(val <= size) {
        tree[val]++;
        val += (val & -val);
    }
}
int tree_qry(int *tree, int size, int val) {
    int ret = 0;
    val += 1;
    while (val) {
        ret += tree[val];
        val -= (val & -val);
    }
    return ret;
}

int get_index(long long *sorted, int size, long long val)
{
    if (val < sorted[0]) {
        return -1;
    }
    int i = 0, j = size;
    int mid;
    while (i < j) {
        mid = i + (j - i) / 2;
        if (sorted[mid] <= val) {
            i = mid + 1;
        } else {
            j = mid;
        }
    }
    return i - 1;
}

int int_cmp(const void *p1, const void *p2)
{
    if (*(long long *)p1 == *(long long*)p2) {
        return 0;
    } else if (*(long long *)p1 > *(long long *)p2) {
        return 1;
    } else {
        return -1;
    }
}
int countRangeSum(int* nums, int numsSize, int lower, int upper){
    if (numsSize == 0) {
        return 0;
    }
    long long *sum = (long long *)malloc(numsSize * sizeof(long long));
	long long *onums = (long long *)malloc(numsSize * sizeof(long long));
    int *tree = (int *)malloc((numsSize + 1)* sizeof(int));
    int i, ret = 0;
    int low, high;
    memset(tree, 0, (numsSize + 1)* sizeof(int));
    sum[0] = nums[0];
	onums[0] = nums[0];
    for (i = 1; i != numsSize; ++i) {
		onums[i] = nums[i];
        onums[i] += onums[i - 1];
        sum[i] = onums[i];
    }
    qsort(sum, numsSize, sizeof(long long), int_cmp);
    for (i = 0; i != numsSize; ++i) {
        if (onums[i] >= lower && onums[i] <= upper) {
            ret += 1;
        }
        low = get_index(sum, numsSize, onums[i] - lower);
        high = get_index(sum, numsSize, onums[i] - upper - 1);
        ret += tree_qry(tree, numsSize, low) -
                tree_qry(tree, numsSize, high);
        tree_add(tree, numsSize, get_index(sum, numsSize, onums[i]));
    }
    return ret;
}
