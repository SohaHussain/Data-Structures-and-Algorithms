// Dijkstra's Algorithm

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push({0,source});	// (dist,source)
	while( !pq.empty() )
  {
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		for( auto it : g[prev])
    {
			int next = it.first;
			int nextDist = it.second;
			if( distTo[next] > dist + nextDist)
      {
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
