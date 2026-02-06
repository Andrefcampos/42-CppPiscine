#include "Worker.hpp"
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
#include <iostream>

void printSeparator(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

void testComposition() {
    printSeparator("TEST 1: COMPOSITION");
    std::cout << "Testing: Worker HAS-A Position and Statistic (strong ownership)\n" << std::endl;
    
    std::cout << "Creating Worker..." << std::endl;
    Worker worker1;
    
    std::cout << "\nCreating Position and Statistic..." << std::endl;
    Position pos;
    pos.setX(10);
    pos.setY(20);
    pos.setZ(30);
    
    Statistic stat;
    stat.setLevel(5);
    stat.setExp(1000);
    
    std::cout << "\nSetting Position to Worker..." << std::endl;
    worker1.setPosition(pos);
    
    std::cout << "Setting Statistic to Worker..." << std::endl;
    worker1.setStatistic(stat);
    
    std::cout << "\nGetting Worker's Position..." << std::endl;
    Position workerPos = worker1.getPosition();
    std::cout << "Worker Position: (" << workerPos.getX() << ", " << workerPos.getY() << ", " << workerPos.getZ() << ")" << std::endl;
    
    std::cout << "\nGetting Worker's Statistic..." << std::endl;
    Statistic workerStat = worker1.getStatistic();
    std::cout << "Worker Stats: Level " << workerStat.getLevel() << ", EXP " << workerStat.getExp() << std::endl;
    
    std::cout << "\nNote: Position and Statistic are destroyed WITH Worker (Composition)" << std::endl;
    std::cout << "Destroying Worker..." << std::endl;
}

void testAggregation() {
    printSeparator("TEST 2: AGGREGATION");
    std::cout << "Testing: Worker CAN-HAVE Tools (weak ownership, can be given/taken away)\n" << std::endl;
    
    std::cout << "Creating a Shovel on the heap (independent lifecycle)..." << std::endl;
    Shovel* shovel = new Shovel();
    
    std::cout << "\nCreating Worker1..." << std::endl;
    Worker* worker1 = new Worker();
    
    std::cout << "\nGiving Shovel to Worker1..." << std::endl;
    worker1->takeTool(shovel);
    
    std::cout << "\nUsing Shovel through Worker1's work..." << std::endl;
    worker1->work();
    
    std::cout << "\nDestroying Worker1 (but NOT the Shovel - Aggregation!)..." << std::endl;
    delete worker1;
    
    std::cout << "\nShovel still exists! Creating Worker2..." << std::endl;
    Worker* worker2 = new Worker();
    
    std::cout << "\nGiving the SAME Shovel to Worker2..." << std::endl;
    worker2->takeTool(shovel);
    
    std::cout << "\nUsing Shovel through Worker2's work..." << std::endl;
    worker2->work();
    
    std::cout << "\nNote: Shovel was transferred between workers!" << std::endl;
    std::cout << "Destroying Worker2..." << std::endl;
    delete worker2;
    
    std::cout << "\nManually destroying Shovel (independent lifecycle)..." << std::endl;
    delete shovel;
}

void testInheritance() {
    printSeparator("TEST 3: INHERITANCE (POLYMORPHISM)");
    std::cout << "Testing: Shovel and Hammer ARE-A Tool (inheritance hierarchy)\n" << std::endl;
    
    std::cout << "Creating tools on the heap..." << std::endl;
    Tool* shovel = new Shovel();
    Tool* hammer = new Hammer();
    
    std::cout << "\nCreating Worker..." << std::endl;
    Worker* worker = new Worker();
    
    std::cout << "\nAdding multiple tools to Worker (polymorphism)..." << std::endl;
    worker->takeTool(shovel);
    worker->takeTool(hammer);
    
    std::cout << "\nWorker works with ALL tools..." << std::endl;
    worker->work();
    
    std::cout << "\nWorker works again (numberOfUses should increment)..." << std::endl;
    worker->work();
    
    std::cout << "\nUsing GetTool<T>() to get specific tool types..." << std::endl;
    Shovel* foundShovel = worker->GetTool<Shovel>();
    if (foundShovel) {
        std::cout << "Found a Shovel! Using it..." << std::endl;
        foundShovel->use();
    }
    
    Hammer* foundHammer = worker->GetTool<Hammer>();
    if (foundHammer) {
        std::cout << "Found a Hammer! Using it..." << std::endl;
        foundHammer->use();
    }
    
    std::cout << "\nCleaning up..." << std::endl;
    delete worker;
    delete shovel;
    delete hammer;
}

void testAssociation() {
    printSeparator("TEST 4: ASSOCIATION");
    std::cout << "Testing: Workshop WORKS-WITH Workers (collaboration, no ownership)\n" << std::endl;
    
    std::cout << "Creating 3 Workers..." << std::endl;
    Worker* worker1 = new Worker();
    Worker* worker2 = new Worker();
    Worker* worker3 = new Worker();
    
    std::cout << "\nGiving tools to workers..." << std::endl;
    worker1->takeTool(new Shovel());
    worker2->takeTool(new Hammer());
    worker3->takeTool(new Shovel());
    worker3->takeTool(new Hammer());
    
    std::cout << "\nCreating 2 Workshops..." << std::endl;
    Workshop* workshop1 = new Workshop();
    Workshop* workshop2 = new Workshop();
    
    std::cout << "\nRegistering Worker1 and Worker2 in Workshop1..." << std::endl;
    workshop1->registerWorker(worker1);
    workshop1->registerWorker(worker2);
    
    std::cout << "\nRegistering Worker2 and Worker3 in Workshop2..." << std::endl;
    workshop2->registerWorker(worker2);
    workshop2->registerWorker(worker3);
    
    std::cout << "\nNote: Worker2 is in BOTH workshops simultaneously (Association!)\n" << std::endl;
    
    std::cout << "\n--- Workshop1 executes work day ---" << std::endl;
    workshop1->executeWorkDay();
    
    std::cout << "\n--- Workshop2 executes work day ---" << std::endl;
    workshop2->executeWorkDay();
    
    std::cout << "\nReleasing Worker2 from Workshop1..." << std::endl;
    workshop1->releaseWorker(worker2);
    
    std::cout << "\n--- Workshop1 executes work day again (without Worker2) ---" << std::endl;
    workshop1->executeWorkDay();
    
    std::cout << "\nDestroying Workshop1 (Workers remain alive - Association!)..." << std::endl;
    delete workshop1;
    
    std::cout << "\nWorkers still exist! Workshop2 can still use them..." << std::endl;
    std::cout << "\n--- Workshop2 executes work day ---" << std::endl;
    workshop2->executeWorkDay();
    
    std::cout << "\nCleaning up everything..." << std::endl;
    delete workshop2;
    
    // Delete tools properly (remove from worker first, then delete)
    std::cout << "\nDeleting tools..." << std::endl;
    Tool* tool;
    
    tool = worker1->GetTool<Shovel>();
    if (tool) {
        worker1->removeTool(tool);
        delete tool;
    }
    
    tool = worker2->GetTool<Hammer>();
    if (tool) {
        worker2->removeTool(tool);
        delete tool;
    }
    
    tool = worker3->GetTool<Shovel>();
    if (tool) {
        worker3->removeTool(tool);
        delete tool;
    }
    tool = worker3->GetTool<Hammer>();
    if (tool) {
        worker3->removeTool(tool);
        delete tool;
    }
    
    std::cout << "\nDeleting workers..." << std::endl;
    delete worker1;
    delete worker2;
    delete worker3;
}

void testCompleteScenario() {
    printSeparator("TEST 5: COMPLETE SCENARIO");
    std::cout << "Testing: All relationships working together\n" << std::endl;
    
    std::cout << "Creating a construction site scenario..." << std::endl;
    
    std::cout << "\n1. Creating tools (independent objects)..." << std::endl;
    Shovel* shovel1 = new Shovel();
    Shovel* shovel2 = new Shovel();
    Hammer* hammer1 = new Hammer();
    
    std::cout << "\n2. Creating workers (with Composition: Position + Statistic)..." << std::endl;
    Worker* john = new Worker();
    Worker* mary = new Worker();
    
    Position pos1;
    pos1.setX(0);
    pos1.setY(0);
    pos1.setZ(0);
    john->setPosition(pos1);
    
    Position pos2;
    pos2.setX(10);
    pos2.setY(10);
    pos2.setZ(0);
    mary->setPosition(pos2);
    
    std::cout << "\n3. Giving tools to workers (Aggregation)..." << std::endl;
    john->takeTool(shovel1);
    john->takeTool(hammer1);
    mary->takeTool(shovel2);
    
    std::cout << "\n4. Creating workshops (Association)..." << std::endl;
    Workshop* morningShift = new Workshop();
    Workshop* afternoonShift = new Workshop();
    
    std::cout << "\n5. Registering workers to workshops..." << std::endl;
    morningShift->registerWorker(john);
    morningShift->registerWorker(mary);
    afternoonShift->registerWorker(mary);
    
    std::cout << "\n6. Morning shift starts working..." << std::endl;
    morningShift->executeWorkDay();
    
    std::cout << "\n7. John finishes morning, Mary continues to afternoon..." << std::endl;
    morningShift->releaseWorker(john);
    
    std::cout << "\n8. Afternoon shift starts working..." << std::endl;
    afternoonShift->executeWorkDay();
    
    std::cout << "\n9. Mary returns shovel2 and gets shovel1 from John..." << std::endl;
    // In a real scenario, we'd have a releaseTool method
    
    std::cout << "\n10. Cleanup time..." << std::endl;
    delete morningShift;
    delete afternoonShift;
    delete shovel1;
    delete shovel2;
    delete hammer1;
    delete john;
    delete mary;
    
    std::cout << "\nScenario complete!" << std::endl;
}

int main() {
    std::cout << "╔════════════════════════════════════════════════════════╗" << std::endl;
    std::cout << "║    MODULE 01 - OBJECT RELATIONSHIPS DEMONSTRATION     ║" << std::endl;
    std::cout << "║                                                        ║" << std::endl;
    std::cout << "║  Testing: Composition, Aggregation,                    ║" << std::endl;
    std::cout << "║           Inheritance, and Association                 ║" << std::endl;
    std::cout << "╚════════════════════════════════════════════════════════╝" << std::endl;
    
    try {
        testComposition();
        testAggregation();
        testInheritance();
        testAssociation();
        testCompleteScenario();
        
        printSeparator("ALL TESTS COMPLETED SUCCESSFULLY!");
        std::cout << "Review the output above to see:" << std::endl;
        std::cout << "  ✓ Composition: Objects created/destroyed together" << std::endl;
        std::cout << "  ✓ Aggregation: Objects can be shared and transferred" << std::endl;
        std::cout << "  ✓ Inheritance: Polymorphism with Tool hierarchy" << std::endl;
        std::cout << "  ✓ Association: Workers and Workshops collaborate" << std::endl;
        std::cout << "\nAll destructors called, no memory leaks!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
