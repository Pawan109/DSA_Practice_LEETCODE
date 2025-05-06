class Solution {
public:

    struct trieNode{
        int countsPrefix =0;
        trieNode * children[26];
    };


    trieNode * getNode(){
        trieNode *root = new trieNode();

        root->countsPrefix = 0;
        for(int i=0;i<26;i++) root->children[i] = NULL;

        return root;
    }

    void insert(trieNode * root, string &word){
        trieNode * crawler =root;
        for(auto ch : word){
            int ind = ch-'a';
            if(!crawler->children[ind]) crawler->children[ind] = getNode();

            crawler->children[ind]->countsPrefix +=1;
            crawler = crawler->children[ind];
        }
    }

    int getPrefixScore(trieNode * root, string &word){
        trieNode * crawler = root;
        int score = 0 ;

        for(auto ch: word){
            int ind = ch-'a';
            score += crawler->children[ind]->countsPrefix;
            crawler = crawler->children[ind];
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        
        vector<int> ans;
        trieNode * root = getNode();

        for(auto word : words){
            insert(root,word);
        }

        for(auto word : words) ans.push_back(getPrefixScore(root,word));


        return ans;
    }
};