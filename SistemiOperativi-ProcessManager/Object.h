#ifndef OBJECT_H
#define OBJECT_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

    extern const void * Object, * Class;

    /*
     *      Attributes
     */

    struct Object {
        const struct Class * class; /* object's description */
    };

    struct Class {
        const struct Object _; /* class' description */
        const char * name; /* class' name */
        const struct Class * super; /* class' super class */
        size_t size; /* class' object's size */
        void * (* ctor) (void * self, va_list * app);
        void * (* dtor) (void * self);
        int (* differ) (const void * self, const void * b);
        int (* puto) (const void * self, FILE * fp);
    };

    /*
     *      Methods
     */

    void * new (const void * class, ...);
    void delete (void * self);

    const void * classOf(const void * self);
    size_t sizeOf(const void * self);
    void * ctor(void * self, va_list * app);
    void * dtor(void * self);
    int differ(const void * self, const void * b);
    int puto(const void * self, FILE * fp);
    const void * super(const void * self);

    void * super_ctor(const void * class, void * self, va_list * app);
    void * super_dtor(const void * class, void * self);
    int super_differ(const void * class, const void * self, const void * b);
    int super_puto(const void * class, const void * self, FILE * fp);

#ifdef __cplusplus
}
#endif

#endif
