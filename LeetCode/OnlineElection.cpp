class TopVotedCandidate {
public:
    std::vector<int> times_; 
    std::vector<int> persons_;
    std::vector<int> winner;
    TopVotedCandidate(vector<int> persons, vector<int> times)
    :times_(times), persons_(persons)
    {
        winner.clear();
        
        std::unordered_map<int, int> freq_;
        for(auto& el : persons)
        {
            freq_[el]++;
            if (freq_[el] > freq_[curr_max])
                curr_max = el;
            // handles the tie boundary case 
            else if (freq_[el]  == freq_[curr_max] )
                curr_max = el;
            winner.push_back(curr_max);       
        }
    }
    
    int q(int t) {
        
        // find time by binary search for index 
        auto ix = std::lower_bound(times_.begin(), times_.end(), t) - times_.begin();
        if (times_[ix] != t )
            ix -=1;
        // this shouldnt work wtf leetcode 
        if (ix >= times_.size())
            ix -=1;

        return winner[ix];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
