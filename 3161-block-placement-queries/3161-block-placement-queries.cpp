constexpr int MaxX = 50001;

class SegTree{
	int n;
	vector<int> tree;
public:
	SegTree(int _n){
		n = _n;
		tree.resize(n * 4, 0);
	}
	int GetMax(int x) const{
		return GetRangeValueInternal(0, x, 1, 0, n - 1);
	}
	void UpdateValue(int index, int newValue){
		UpdateValueInternal(index, newValue, 1, 0, n - 1);
	}
private:
	int GetRangeValueInternal(int left, int right, int nodeIndex, int nodeRangeLeftIndex, int nodeRangeRightIndex) const{
		if (left > right)return 0;
		if (left == nodeRangeLeftIndex && right == nodeRangeRightIndex)return tree[nodeIndex];
		int rangeMid = (nodeRangeLeftIndex + nodeRangeRightIndex) / 2;
		int leftV = GetRangeValueInternal(left, min(right, rangeMid), nodeIndex * 2, nodeRangeLeftIndex, rangeMid);
		int rightV = GetRangeValueInternal(max(left, rangeMid + 1), right, nodeIndex * 2 + 1, rangeMid + 1, nodeRangeRightIndex);
		return max(leftV, rightV);
	}
	void UpdateValueInternal(int index, int newValue, int nodeIndex, int nodeRangeLeftIndex, int nodeRangeRightIndex){
		if (nodeRangeLeftIndex == nodeRangeRightIndex){
			tree[nodeIndex] = newValue;
			return;
		}
		int mid = (nodeRangeLeftIndex + nodeRangeRightIndex) / 2;
		int leftChild = nodeIndex * 2;
		int rightChild = leftChild + 1;
		if (index <= mid){
			UpdateValueInternal(index, newValue, leftChild, nodeRangeLeftIndex, mid);
		}else{
			UpdateValueInternal(index, newValue, rightChild, mid + 1, nodeRangeRightIndex);
		}
		tree[nodeIndex] = max(tree[leftChild], tree[rightChild]);
	}
};
class Solution
{
public:
	vector<bool> getResults(vector<vector<int>>& queries)
	{
		SegTree seg(MaxX);
		set<int> obs;
		obs.insert(0);
		obs.insert(MaxX);
		vector<bool> ans;
		for (auto& q : queries){
			int x = q[1];
			if (q[0] == 1){
				auto itr = obs.upper_bound(x);
				int r = *itr;
				int l = *(--itr);
				obs.insert(x);
				seg.UpdateValue(x, x - l);
				seg.UpdateValue(r, r - x);
			}
			else{
				int sz = q[2];
                bool isValid = seg.GetMax(x) >= sz;
                if (!isValid){
					auto itr = obs.lower_bound(x);
					if (*itr != x){
                        int l = *(--itr);
						isValid = (x - l) >= sz;
					}
				}
				ans.push_back(isValid);
			}
		}
		return ans;
	}
};