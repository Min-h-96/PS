/* **************************************************************
    길 찾기 게임
************************************************************** */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    int n;
    Node* left;
    Node* right;
};

bool cmp(Node a, Node b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y > b.y;
}

void addNode(Node* parent, Node* child) {
    if (child->x < parent->x) {
        if (parent->left != NULL)
            addNode(parent->left, child);
        else
            parent->left = child;
    } else {
        if (parent->right != NULL)
            addNode(parent->right, child);
        else
            parent->right = child;
    }
}

void preorder(vector<int>& answer, Node* node) {
    if (node != NULL) {
        answer.push_back(node->n);
        preorder(answer, node->left);
        preorder(answer, node->right);
    }
}

void postorder(vector<int>& answer, Node* node) {
    if (node != NULL) {
        postorder(answer, node->left);
        postorder(answer, node->right);
        answer.push_back(node->n);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    vector<Node> nodes;
    Node* root;
    
    //노드 저장
    for (auto i=0; i<nodeinfo.size(); i++) {
        Node node;
        node.x = nodeinfo[i][0];
        node.y = nodeinfo[i][1];
        node.n = i + 1;
        nodes.push_back(node);
    }
    
    //노드 y좌표 값으로 레벨 정렬 + 레벨이 같다면 x좌표 값으로 왼쪽, 오른쪽 서브트리 정렬
    sort(nodes.begin(), nodes.end(), cmp);
    
    //루트 노드
    root = &nodes[0];
    
    //left, right 설정하며 이진트리에 노드 추가
    for (auto i=1; i<nodes.size(); i++)
        addNode(root, &nodes[i]);
    
    preorder(answer[0], root);
    postorder(answer[1], root);
    
    return answer;
}