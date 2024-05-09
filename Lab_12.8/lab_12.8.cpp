#include <iostream>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

struct Place {
    string name;
    int distance;
    Place* next;
    Place* prev;
};

struct Pair {
    string first;
    string second;
};

void Insert(Place*& head, const string& name, int distance) {
    Place* newPlace = new Place{ name, distance, nullptr, nullptr };
    if (head == nullptr) {
        head = newPlace;
        head->next = head;
        head->prev = head;
    }
    else {
        Place* last = head->prev;
        last->next = newPlace;
        newPlace->prev = last;
        newPlace->next = head;
        head->prev = newPlace;
    }
}

void PrintList(Place* head) {
    if (head == nullptr) return;
    Place* current = head;
    do {
        cout << current->name << " -> " << current->distance << " km | ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int FindDistance(Place* head, const string& start, const string& end) {
    if (!head) return -1;
    Place* current = head;
    int totalDistance = 0;
    bool started = false;

    do {
        if (current->name == start) started = true;
        if (started) {
            totalDistance += current->distance;
            if (current->name == end) return totalDistance - current->distance;
        }
        current = current->next;
    } while (current != head);

    return -1;
}

Pair FindClosestDistance(Place* head, int targetDistance) {
    Pair result = { "", "" };
    if (!head) return result;
    int minDiff = INT_MAX;
    Place* current = head;

    do {
        int diff = abs(current->distance - targetDistance);
        if (diff < minDiff) {
            minDiff = diff;
            result.first = current->name;
            result.second = current->next->name;
            if (diff == 0) break;
        }
        current = current->next;
    } while (current != head);

    return result;
}

int main() {
    Place* head = nullptr;
    Insert(head, "Dro", 140);
    Insert(head, "Lviv", 150);
    Insert(head, "Stryj", 90);
    Insert(head, "Stebnyk", 120);

    PrintList(head);

    string from = "Dro", to = "Stryj";
    int distance = FindDistance(head, from, to);
    cout << "The distance between " << from << " and " << to << " is: " << distance << " km\n";

    int targetDistance = 120;
    Pair closest = FindClosestDistance(head, targetDistance);
    cout << "The closest distance to " << targetDistance << " km is between " << closest.first << " and " << closest.second << ".\n";

    return 0;
}