class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefix(13,0);
        int sum = 0;
        for(int i = 1; i < 13; i++){
            sum += months[i];
            prefix[i] = sum;
        }
        string ma = arriveAlice.substr(0, 2);
        string da = arriveAlice.substr(3, 2);

        string mae = leaveAlice.substr(0, 2);
        string dae = leaveAlice.substr(3, 2);

        string mb = arriveBob.substr(0, 2);
        string db = arriveBob.substr(3, 2);

        string mbe = leaveBob.substr(0, 2);
        string dbe = leaveBob.substr(3, 2);

        int arriveAmonth = stoi(ma);
        int arriveAday = stoi(da);

        int endAmonth = stoi(mae);
        int endAday = stoi(dae);

        int arriveBmonth = stoi(mb);
        int arriveBday = stoi(db);

        int endBmonth = stoi(mbe);
        int endBday = stoi(dbe);

        int AAlice = prefix[arriveAmonth - 1] + arriveAday;
        int EAlice = prefix[endAmonth - 1] + endAday;

        int ABob = prefix[arriveBmonth - 1] + arriveBday;
        int EBob = prefix[endBmonth - 1] + endBday;

        int maxi = max(AAlice, ABob);
        int mini = min(EAlice, EBob);

        return maxi > mini?0:mini - maxi + 1;
    }
};