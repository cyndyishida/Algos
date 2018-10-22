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
        auto curr_max = persons[0];
        freq_[0] = 1;
        winner.push_back(curr_max);
        for(int i = 1; i < persons.size(); ++i)
        {
            freq_[persons[i]]++;
            if (freq_[persons[i]] > freq_[curr_max])
                curr_max = persons[i];
            else if (freq_[persons[i]]  == freq_[curr_max] )
                curr_max = persons[i];
            
            
            winner.push_back(curr_max);       
        }
    }
    
    int q(int t) {
        
        // find time by binary search for index 
        auto ix = std::lower_bound(times_.begin(), times_.end(), t) - times_.begin();
        if (times_[ix] != t )
            ix -=1;
        return winner[ix];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
