class Solution {
private:
    struct Car
    {
        float time;
        int pos;
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 1)
            return 1;

        std::vector<Car> cars;
        for (int i = 0; i < position.size(); ++i)
        {
            cars.emplace_back(Car{
                    .time = (float)(target - position[i]) / (float)(speed[i]),
                    .pos = position[i], 
                });
        }
        position.clear();
        speed.clear();

        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){
            return a.pos > b.pos;
        });

        int numFleet = 1;
        Car* tail = &cars[0];
        float leadFleetTime = tail->time;

        for (int i = 1; i < cars.size(); ++i)
        {
            if (cars[i].time > leadFleetTime)
            {
                tail = &cars[i];
                leadFleetTime = tail->time;
                numFleet += 1;
            }

        }

        return numFleet;
    }
};
