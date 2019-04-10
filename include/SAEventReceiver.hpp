/**
 *  SimpleAssets - Event Receiver Example (Digital Assets)
 *  (C) 2019 by CryptoLions [ https://CryptoLions.io ]
 *
 *  SimpleAssets - A simple standard for digital assets (ie. Non-Fungible Tokens) for EOSIO blockchains
 *
 *    WebSite:        https://simpleassets.io
 *    GitHub:         https://github.com/CryptoLions/SimpleAssets 
 *    Presentation:   https://medium.com/@cryptolions/introducing-simple-assets-b4e17caafaa4
 * 
 */
 
#include <eosiolib/eosio.hpp>
using namespace eosio;

name SIMPLEASSETS_CONTRACT = "simpl1assets"_n; // SimpleAssets Contract Account

CONTRACT SAEventReceiver : public contract {
	public:
		using contract::contract;

		ACTION saecreate( name owner, uint64_t assetid );
		using saecreate_action = action_wrapper<"saecreate"_n, &SAEventReceiver::saecreate>;

		ACTION saetransfer( name from, name to, std::vector<uint64_t>& assetids, std::string memo );
		using saetransfer_action = action_wrapper<"saetransfer"_n, &SAEventReceiver::saetransfer>;

		ACTION saeclaim( name who, std::map< uint64_t, name >& assetids );
		using saeclaim_action = action_wrapper<"saeclaim"_n, &SAEventReceiver::saeclaim>;

		ACTION saeburn( name who, std::vector<uint64_t>& assetids, std::string memo );
		using saeburn_action = action_wrapper<"saeburn"_n, &SAEventReceiver::saeburn>;
	
};
