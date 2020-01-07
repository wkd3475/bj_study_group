#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//<key, pair<computers, isVisted>>
map <int, pair<vector<int>*, int> > vector_map;
int max_num = 0;
vector<int> max_result;

int dps(int key, int visited_key);

int main(void) {
    int N, M;
    int from, to;
    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; i++) {
        vector<int>* computer = new vector<int>();
        vector_map[i].first = computer;
        vector_map[i].second = 0;
    }

    for (int i=0; i<M; i++) {
        scanf("%d %d", &from, &to);
        vector_map[to].first->push_back(from);
    }

    map<int, pair<vector<int>*, int> >::iterator it_vector_map;
    for(it_vector_map = vector_map.begin(); it_vector_map != vector_map.end(); it_vector_map++) {
        dps(it_vector_map->first, it_vector_map->first);
    }
    sort(max_result.begin(), max_result.end());

    vector<int>::iterator it_vector;
    for (it_vector = max_result.begin(); it_vector != max_result.end(); it_vector++) {
        printf("%d ", *it_vector);
    }
    printf("\n");
    return 0;
}

int dps(int key, int visited_key) {
    int local_max = 1;
    vector_map[key].second = key;

    vector<int>::iterator it_vector;
    for (it_vector = vector_map[key].first->begin(); it_vector != vector_map[key].first->end(); it_vector++) {
        if (*it_vector != visited_key) {
            local_max += dps(*it_vector, visited_key);
        }
    }

    if (local_max>max_num) {
        max_num = local_max;
        max_result.clear();
        max_result.push_back(key);
    } else if(local_max == max_num) {
        max_result.push_back(key);
    }

    return local_max;
}