
struct trieNode{
    trieNode * children[26];
    int count;

};

class Solution {
public:


trieNode * getNode(){
    trieNode * newNode = new trieNode();
    newNode->count=0;
    for(int i=0;i<26;i++) newNode->children[i]=NULL;
    return newNode;
}


void insert(string &word , trieNode *root){
    trieNode * crawl = root;

    for(char &ch: word){
        int ind = ch-'a';

        if(!crawl->children[ind]) crawl->children[ind]=getNode();

        crawl->children[ind]->count += 1;
        crawl = crawl->children[ind];
    }
}


    string longestCommonPrefix(vector<string>& strs) {
        
        trieNode * root = getNode();

        for(string &word : strs){
            insert(word,root);
        }

        string ans="";
        
        trieNode * crawl = root;
        for(auto ch: strs[0]){ //we can take any word not just strs[0]
            
                int ind = ch-'a';

                if(crawl->children[ind] && crawl->children[ind]->count==strs.size()){
                    ans+=ch;
                    crawl = crawl->children[ind];
                } 
                else break;
            
        }

        return ans;
    }
};