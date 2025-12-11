#ifndef OBS
#define OBS 

template <size_t N>
class Observateur {
public:
	virtual ~Observateur() = default;
	// L'unique méthode de notification (pure event-based)
	virtual void onNotify(const Evenement<N>& event) = 0;
};

#endif