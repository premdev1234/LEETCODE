class Encrypter {
    unordered_map<char, string> kv;
    unordered_map<string, int> encCount;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dict) {
        for (int i = 0; i < keys.size(); ++i) 
            kv[keys[i]] = values[i];
        
        for (auto& word : dict) {
            string e = "";
            for (char c : word) {
                if (!kv.count(c)) {
                    e = "";
                    break;
                }
                e += kv[c];
            }
            if (!e.empty()) encCount[e]++;
        }
    }
    
    string encrypt(string word) {
        string res;
        for (char c : word) {
            if (!kv.count(c)) return "";
            res += kv[c];
        }
        return res;
    }
    
    int decrypt(string word) {
        return encCount.count(word) ? encCount[word] : 0;
    }
};
