#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return (left->frequency > right->frequency);
    }
};

HuffmanNode* buildHuffmanTree(map<char, unsigned> frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (const auto& entry : frequencies) {
        pq.push(new HuffmanNode(entry.first, entry.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

void buildHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        huffmanCodes[root->data] = code;
    }

    buildHuffmanCodes(root->left, code + "0", huffmanCodes);
    buildHuffmanCodes(root->right, code + "1", huffmanCodes);
}

string encode(string text, map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }
    return encodedText;
}

string decode(HuffmanNode* root, string encodedText) {
    string decodedText = "";
    HuffmanNode* current = root;

    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedText += current->data;
            current = root;
        }
    }

    return decodedText;
}

int main() {
    map<char, unsigned> frequencies = {
        {'a', 5},
        {'b', 9},
        {'c', 12},
        {'d', 13},
        {'e', 16},
        {'f', 45}
    };

    HuffmanNode* root = buildHuffmanTree(frequencies);

    map<char, string> huffmanCodes;
    buildHuffmanCodes(root, "", huffmanCodes);

    string text = "abcdef";
    string encodedText = encode(text, huffmanCodes);
    string decodedText = decode(root, encodedText);

    cout << "Original text: " << text << endl;
    cout << "Encoded text: " << encodedText << endl;
    cout << "Decoded text: " << decodedText << endl;

    return 0;
}
