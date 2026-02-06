#pragma once
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include <vector>
#include <cstddef>

class Workshop;

class Worker {
    private:
        Position coordonnee;
        Statistic stat;
        std::vector<Tool*> tools;
        std::vector<Workshop*> workshops;

    public:
        Worker();
        ~Worker();

        Position getPosition() const;
        Statistic getStatistic() const;

        void setPosition(const Position &pos);
        void setStatistic(const Statistic &stat);

        void takeTool(Tool* tool);
        void removeTool(Tool* tool);

        void work();

        void registerToWorkshop(Workshop* workshop);
        void leaveWorkshop(Workshop* workshop);

        template<typename ToolType>
        ToolType* GetTool() const {
            for (size_t i = 0; i < tools.size(); i++) {
                ToolType* casted = dynamic_cast<ToolType*>(tools[i]);
                if (casted != NULL)
                    return casted;
            }
            return NULL;
        }
};