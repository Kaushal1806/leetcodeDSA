class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
    int energyTrainingHours = 0;
    int experienceTrainingHours = 0;

    // Iterate through each opponent
    for (int i = 0; i < energy.size(); i++) {
        // Ensure sufficient energy
        if (initialEnergy <= energy[i]) {
            energyTrainingHours += (energy[i] - initialEnergy + 1);
            initialEnergy = energy[i] + 1; // Update initialEnergy after training
        }
        initialEnergy -= energy[i]; // Deduct energy after defeating the opponent

        // Ensure sufficient experience
        if (initialExperience <= experience[i]) {
            experienceTrainingHours += (experience[i] - initialExperience + 1);
            initialExperience = experience[i] + 1; // Update initialExperience after training
        }
        initialExperience += experience[i]; // Gain experience after defeating the opponent
    }

    return energyTrainingHours + experienceTrainingHours;
}

};