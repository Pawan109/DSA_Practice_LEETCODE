struct trieNode{
    trieNode * children[26];
    bool endOfWord;
};

trieNode * getNode(){
    trieNode * root = new trieNode();
    root->endOfWord = false;

    for(int i=0;i<26;i++) root->children[i] = NULL;

    return root;
}

class Trie{

    public : 
    trieNode * root;

    Trie(){
        root = getNode();
    }

    void insert(string word){
        trieNode * crawl = root;

        for(auto ch : word){
            int ind = ch-'a';
            if(!crawl->children[ind]) crawl->children[ind] = getNode();

            crawl = crawl->children[ind];
        }
        crawl->endOfWord = true;
    }

    bool searchPrefix(string prefix){
        trieNode * crawl = root;

        for(auto ch : prefix){ //iterate the prefix
            int ind = ch-'a';
            if(!crawl->children[ind]) return false;

            crawl = crawl->children[ind];
        }
       return true;
    }
};

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for( int i=0;i<n;i++){
            Trie prefixTrie;
            Trie suffixTrie;

            prefixTrie.insert(words[i]);
            string rev = words[i];

            reverse(rev.begin(), rev.end());

            suffixTrie.insert(rev);
        //toh humne s1 ko as a prefix and suffix daal diya Tries mein 
        //ab s2 ke saath dono ends check karne hai bss
        
            for(int j=0;j<i;j++){
                if(words[j].size() > words[i].size()) continue;

                string rev2 = words[j];
                reverse(rev2.begin() , rev2.end());

                if(prefixTrie.searchPrefix(words[j]) && suffixTrie.searchPrefix(rev2) ) count++;
            }
        }
        return count;
    }
};