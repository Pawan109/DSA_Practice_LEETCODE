class Solution {
public:

     struct trieNode {
        int countsPrefix = 0;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* node = new trieNode();
        for (int i = 0; i < 26; i++) node->children[i] = NULL;
        return node;
    }

     void insert(trieNode* root, string& word) {
        trieNode* crawler = root;
        for (char ch : word) {
            int ind = ch - 'a';
            if (!crawler->children[ind])
                crawler->children[ind] = getNode();

            // Increment the count on the child node
            crawler->children[ind]->countsPrefix++;

            // Move to the child node
            crawler = crawler->children[ind];
        }
    }

      int countWordsWithPrefix(trieNode* root, const string& pref) {
        trieNode* crawler = root;
        for (char ch : pref) {
            int ind = ch - 'a';
            if (!crawler->children[ind])
                return 0;

            crawler = crawler->children[ind];
        }

        return crawler->countsPrefix;
    }



    int prefixCount(vector<string>& words, string pref) {
         trieNode* root = getNode();

        for (string& word : words) {
            insert(root, word);
        }

        return countWordsWithPrefix(root, pref);
    }
};