/**
 *  SimpleAssets - Event Receiver Example (Digital Assets)
 *  (C) 2020 by CryptoLions [ https://CryptoLions.io ]
 *
 *  SimpleAssets - A simple standard for digital assets (ie. Non-Fungible Tokens) for EOSIO blockchains
 *
 *    WebSite:        https://simpleassets.io
 *    GitHub:         https://github.com/CryptoLions/SimpleAssets 
 *    Presentation:   https://medium.com/@cryptolions/introducing-simple-assets-b4e17caafaa4
 * 
 */
 
#include <eosio/eosio.hpp>
using namespace eosio;
using namespace std;

name SIMPLEASSETS_CONTRACT = "simpleassets"_n; // SimpleAssets Contract Account

CONTRACT SAEventReceiver : public contract {
	public:
		using contract::contract;

		ACTION hi();
		using hi_action = action_wrapper<"hi"_n, &SAEventReceiver::hi>;

	public:
		void saecreate(name author, name category, name owner, string idata, string mdata, uint64_t assetid, bool requireclaim);
		void saetransfer(name author, name from, name to, vector<uint64_t>& assetids, string memo);
		void saeburn(name author, name owner, vector<uint64_t>& assetids, string memo);
		void saechauthor(name author, name newauthor, name owner, map< uint64_t, name >& assetids, string memo);
		void saeclaim(name author, name claimer, map< uint64_t, name >& assetids);
};

extern "C"
void apply(uint64_t receiver, uint64_t code, uint64_t action) {

	if (code == SIMPLEASSETS_CONTRACT.value && action == "saecreate"_n.value) {
		eosio::execute_action(eosio::name(receiver), eosio::name(code), &SAEventReceiver::saecreate);
	}
	else if (code == SIMPLEASSETS_CONTRACT.value && action == "saetransfer"_n.value) {

		eosio::execute_action(eosio::name(receiver), eosio::name(code), &SAEventReceiver::saetransfer);
	}
	else if (code == SIMPLEASSETS_CONTRACT.value && action == "saeburn"_n.value) {

		eosio::execute_action(eosio::name(receiver), eosio::name(code), &SAEventReceiver::saeburn);
	}
	else if (code == SIMPLEASSETS_CONTRACT.value && action == "saechauthor"_n.value) {

		eosio::execute_action(eosio::name(receiver), eosio::name(code), &SAEventReceiver::saechauthor);
	}
	else if (code == SIMPLEASSETS_CONTRACT.value && action == "saeclaim"_n.value) {

		eosio::execute_action(eosio::name(receiver), eosio::name(code), &SAEventReceiver::saeclaim);
	}
	else if (code == receiver) {

		switch (action) {
			EOSIO_DISPATCH_HELPER(SAEventReceiver, (hi))
		}
	}
}