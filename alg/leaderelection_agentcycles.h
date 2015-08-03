#ifndef LEADERELECTION_AGENTCYCLES_H
#define LEADERELECTION_AGENTCYCLES_H

#include "alg/algorithmwithflags.h"

class System;

namespace LeaderElectionAgentCycles
{

enum class State {
    Idle,
    Candidate,
    Demoted,
    Leader,
    Finished
};

typedef struct {
    int agentDir, nextAgentDir, prevAgentDir;
    State state;
} Agent;

class LeaderElectionAgentCyclesFlag : public Flag
{
public:
    LeaderElectionAgentCyclesFlag();
    LeaderElectionAgentCyclesFlag(const LeaderElectionAgentCyclesFlag& other);

    State state;
    int announceToken, ackToken;
    bool receivedAnnounceToken, receivedAckToken;
};

class LeaderElectionAgentCycles : public AlgorithmWithFlags<LeaderElectionAgentCyclesFlag>
{
public:
    LeaderElectionAgentCycles(const State _state);
    LeaderElectionAgentCycles(const LeaderElectionAgentCycles& other);
    virtual ~LeaderElectionAgentCycles();

    static std::shared_ptr<System> instance(const unsigned int size);
    virtual Movement execute();
    virtual std::shared_ptr<Algorithm> clone() override;
    virtual bool isDeterministic() const;

protected:
    void setState(const State _state);
    void setAgentState(const int agentDir, const State state);
    void updateParticleState();
    void updateBorderColors();
    bool hasAgentInState(State state) const;
    int getNextAgentDir(const int agentDir) const;
    int getPrevAgentDir(const int agentDir) const;
    int numNeighbors() const;

    State state;
    std::array<Agent, 3> agents;

    // information for coin flip subphase
    bool waitingForTransferAck;
    bool gotAnnounceBeforeAck;
};

}

#endif // LEADERELECTION_AGENTCYCLES_H
