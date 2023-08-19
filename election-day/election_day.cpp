#include <algorithm>
#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};

    bool operator<(const ElectionResult &rhs) const {
        return votes < rhs.votes;
    }
};

// vote_count takes a reference to an `ElectionResult` as an argument and will
// return the number of votes in the `ElectionResult.
int vote_count(ElectionResult &result) {
    return result.votes;
}

// increment_vote_count takes a reference to an `ElectionResult` as an argument
// and a number of votes (int), and will increment the `ElectionResult` by that
// number of votes.
void increment_vote_count(ElectionResult &result, int more) {
    result.votes = result.votes + more;
}

// determine_result receives the reference to a final_count and returns a
// reference to the `ElectionResult` of the new president. It also changes the
// name of the winner by prefixing it with "President". The final count is given
// in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
// `ElectionResults` of all the participating candidates.
ElectionResult &determine_result(std::vector<ElectionResult> &candidates) {
    ElectionResult &president = [&candidates]() -> ElectionResult& {
        std::sort(candidates.begin(), candidates.end());

        return candidates.back();
    }();

    president.name = "President " + president.name;

    return president;
}

}  // namespace election
