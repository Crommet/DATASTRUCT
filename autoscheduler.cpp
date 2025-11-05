//auto scheduler based on starting and finishing times 
//three variabls are needed: the activity, start time, finish time 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start;
    int finish;
    Activity() : start(0), finish(0) {}
};
//prefered activity inherits from Activity
struct PreferedActivity : public Activity {
    char id; //activity identifier
    PreferedActivity(int i, int s, int f) : id(i) {
        start = s;
        finish = f;
    }
};
//function to compare two activities based on finish time
bool activityCompare(PreferedActivity a1, PreferedActivity a2) {
    return (a1.finish < a2.finish);
}
//function to perform activity selection
void selectActivities(vector<PreferedActivity> activities) {
    //sort activities based on finish time
    sort(activities.begin(), activities.end(), activityCompare);
    cout << "Selected activities are: " << endl;
    int n = activities.size();
    int lastFinishTime = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            cout << "Activity " << activities[i].id << " ("
                 << activities[i].start << ", "
                 << activities[i].finish << ")" << endl;
            lastFinishTime = activities[i].finish;
        }
    }
}
int main() {
    vector<PreferedActivity> activities;
    activities.push_back(PreferedActivity('A', 1, 7));
    activities.push_back(PreferedActivity('B', 2, 3));
    activities.push_back(PreferedActivity('C', 4, 5));
    activities.push_back(PreferedActivity('D', 6, 8));
    activities.push_back(PreferedActivity('E', 9, 10));
    activities.push_back(PreferedActivity('F', 8, 11));

    selectActivities(activities);
    return 0;
}