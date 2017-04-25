class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	    vector<double> res;
	    unordered_map<string, unordered_map<string,double> > map;
	    for (int i=0; i<equations.size(); i++){
	        map[equations[i].first][equations[i].second] = values[i];
	        map[equations[i].second][equations[i].first] = 1.0/values[i];
	    }
	    for (int i=0; i<queries.size(); i++){
	        unordered_set<string> visited;
	        double tmp = find_division(queries[i].first, queries[i].second, map, visited);
	        if (tmp==0) res.push_back(-1.0);
	        else res.push_back(tmp);
	        visited.clear();
	    }
	    return res;
    }
private:
    double find_division(string start, string end, unordered_map<string, unordered_map<string,double> > &map, unordered_set<string> &visited){
        if (map.find(start)==map.end()) return 0.0;
        if (visited.find(start)!=visited.end()) return 0.0;
        if (start==end) return 1.0;
        
        visited.insert(start);
        double prod;
        for (auto t:map[start]){
            prod = t.second * find_division(t.first,end,map,visited);
            if (prod!=0) return prod;
        }
        visited.erase(start);
        return prod;
    }
};