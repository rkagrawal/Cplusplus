#include <iostream>
#include <variant>
#include <cassert>

struct DoorState {
    struct DoorOpened {};
    struct DoorClosed {};
    struct DoorLocked {};

    using State = std::variant<DoorOpened, DoorClosed, DoorLocked>;
    
    void open() {
        m_state = std::visit(OpenEvent{}, m_state);
    }
    
    void close() {
        m_state = std::visit(CloseEvent{}, m_state);
    }

    void lock() {
        m_state = std::visit(LockEvent{}, m_state);
    }
    
    void unlock() {
        m_state = std::visit(UnlockEvent{}, m_state);
    }
    
    struct OpenEvent {
        State operator()(const DoorOpened&){ 
			std::cerr << "Door open event on an open door -- no change\n";
			return DoorOpened(); 
		}
        State operator()(const DoorClosed&){ 
			std::cerr << "Door open event on an closed door -- door opened\n";
			return DoorOpened(); 
		}
        // cannot open locked doors
        State operator()(const DoorLocked&){ 
			std::cerr << "Door locked event on an locked  door -- door locked\n";
			return DoorLocked(); 
		} 
    };
    
    struct CloseEvent {
        State operator()(const DoorOpened&){ 
			std::cerr << "Door closed event on an open  door -- door closed\n";
			return DoorClosed(); 
		}
        State operator()(const DoorClosed&){ 
			std::cerr << "Door closed event on an closed  door -- door closed\n";
			return DoorClosed(); 
		}
        State operator()(const DoorLocked&){ 
			std::cerr << "Door closed event on an locked  door -- door locked\n";
			return DoorLocked(); 
		}
    };
    
    struct LockEvent {
        // cannot lock opened doors
        State operator()(const DoorOpened&){ 
			std::cerr << "Door lock event on an open  door -- door opened\n";
			return DoorOpened(); 
		}
        State operator()(const DoorClosed&){ 
			std::cerr << "Door lock event on an closed  door -- door locked\n";
			return DoorLocked(); 
		}
        State operator()(const DoorLocked&){ 
			std::cerr << "Door lock event on an locked  door -- door locked\n";
			return DoorLocked(); 
		}
    };
    
    struct UnlockEvent {
        // cannot unlock opened doors
        State operator()(const DoorOpened&){ 
			std::cerr << "Door unlock event on an open  door -- door opened\n";
			return DoorOpened(); 
		}
        State operator()(const DoorClosed&){ 
			std::cerr << "Door unlock event on an closed door  door -- door closed\n";
			return DoorClosed(); 
		}
        // unlock
        State operator()(const DoorLocked&){ 
			std::cerr << "Door unlock event on an locked door  door -- door closed\n";
			return DoorClosed(); 
		} 
    };

    State m_state;
};

int main() {
    DoorState s;
    assert(std::holds_alternative<DoorState::DoorOpened>(s.m_state));
    s.lock();
    assert(std::holds_alternative<DoorState::DoorOpened>(s.m_state));
    s.close();
    assert(std::holds_alternative<DoorState::DoorClosed>(s.m_state));
    s.lock();
    assert(std::holds_alternative<DoorState::DoorLocked>(s.m_state));
    s.open();
    assert(std::holds_alternative<DoorState::DoorLocked>(s.m_state));
    
    return 0;
}
