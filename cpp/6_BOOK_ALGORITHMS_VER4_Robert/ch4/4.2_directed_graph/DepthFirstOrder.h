class DepthFirstOrder
{
	private:
		vector<bool> mMarked;
		deque<int> mPre;
		deque<int> mPost;
		vector<int> mReversePost;
	public:
		DepthFirstOrder(Digraph*G)
		{
			mMarked.resize(G->V(),0);
			for(int v=0;v<G->V();v++)
			{
				if(!mMarked[v])
					dfs(G,v);
			}
		}
	private:
		void dfs(Digraph* G,int v)
		{
			mPre.push_back(v);
			mMarked[v]=1;
			for(int w:G->adj(v))
			{
				if(!mMarked[w])
					dfs(G,w);
			}
			mPost.push_back(v);
			mReversePost.push_back(v);
		}
	public:
		deque<int> pre()
		{
			return mPre;
		}
		deque<int> post()
		{
			return mPost;
		}
		vector<int> reversePost()
		{
			return mReversePost;
		}
};
