/*
 * Copyright (C) 2018 Sistemas Operativos - UTN FRBA. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <parsi/parser.h>
#include <cspecs/cspec.h>

context (parsi) {

    describe ("Malas lineas") {
        it ("no puede interpretar algo nulo") {
            t_esi_operacion parsed = parse(NULL);

            should_bool( parsed.valido ) be equal to(false);
        } end

        it ("no puede interpretar una linea vacia") {
            char * line = "";
            t_esi_operacion parsed = parse(line);

            should_bool( parsed.valido ) be equal to(false);
        } end

        it ("no puede interpretar una linea que no empieze con algun keyword conocido") {
            char * line = "sarlanga";
            t_esi_operacion parsed = parse(line);

            should_bool( parsed.valido ) be equal to(false);
        } end

        it ("Si no tiene clave, no es valido") {
            char * line = "GET";
            t_esi_operacion parsed = parse(line);

            should_bool( parsed.valido ) be equal to(false);
        } end

        it ("Si la clave supera los 40 caracteres, no es valido") {
            char * line = "GET 12345678901234567890123456789012345678901234567890";
            t_esi_operacion parsed = parse(line);

            should_bool( parsed.valido ) be equal to(false);
        } end

    } end

    describe ("Buenas lineas"){
        t_esi_operacion parsed;
        after {
            destruir_operacion(parsed);
        } end
        describe ("GET") {

            it ("uno bien escrito deberia parsearse bien") {
                char * line = "GET juego:football";
                parsed = parse(line);

                should_bool( parsed.valido ) be equal to(true);
                should_int( parsed.keyword ) be equal to(GET);
                should_string( parsed.argumentos.GET.clave ) be equal to("juego:football");
            } end

            it ("no importa si hay whitespace antes o despues") {
                char * line = "\t   \tGET juego:football\t \t  ";
                parsed = parse(line);

                should_bool( parsed.valido ) be equal to(true);
                should_int( parsed.keyword ) be equal to(GET);
                should_string( parsed.argumentos.GET.clave ) be equal to("juego:football");
            } end

        } end

        describe ("STORE") {

            it ("uno bien escrito deberia parsearse bien") {
                char * line = "STORE juego:football";
                parsed = parse(line);

                should_bool( parsed.valido ) be equal to(true);
                should_int( parsed.keyword ) be equal to(STORE);
                should_string( parsed.argumentos.STORE.clave ) be equal to("juego:football");
            } end

            it ("no importa si hay whitespace antes o despues") {
                char * line = "\t  STORE juego:football\t ";
                parsed = parse(line);

                should_bool( parsed.valido ) be equal to(true);
                should_int( parsed.keyword ) be equal to(STORE);
                should_string( parsed.argumentos.STORE.clave ) be equal to("juego:football");
            } end

        } end

        describe ("SET") {

            it ("un SET bien escrito deberia parsearse bien") {
                char * line = "SET juego:football messi";
                parsed = parse(line);

                should_bool( parsed.valido ) be equal to(true);
                should_int( parsed.keyword ) be equal to(SET);
                should_string( parsed.argumentos.SET.clave ) be equal to("juego:football");
                should_string( parsed.argumentos.SET.valor ) be equal to("messi");
            } end

            it ("no importa si hay whitespace antes o despues") {
                char * line = "\t SET juego:football messi \t  ";
                parsed = parse(line);

                should_bool( parsed.valido ) be equal to(true);
                should_int( parsed.keyword ) be equal to(SET);
                should_string( parsed.argumentos.GET.clave ) be equal to("juego:football");
                should_string( parsed.argumentos.SET.valor ) be equal to("messi");
            } end

            it ("si el valor tiene espacios, igual quedan del lado del valor") {
                char * line = "\t SET juego:football messi es un gran jugador \t  ";
                parsed = parse(line);

                should_string( parsed.argumentos.SET.valor ) be equal to("messi es un gran jugador");
            } end

        } end
    
    } end

}